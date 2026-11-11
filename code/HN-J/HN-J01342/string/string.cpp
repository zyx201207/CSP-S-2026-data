#include<bits/stdc++.h>
using namespace std;
struct nf{
	int a;
	char s;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie();
	cout.tie();
	int n;
    long long ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		long long l;
		char s;
		cin>>l>>s;
        a[i].a=l;
        a[i].s=s;
	}
	int i=0,j=n-1;
	while(i<j){
        //cout<<ans<<endl;
		if(a[i].s==a[j].s){
			if(a[i].a==a[j].a){
				i++;
				j--;
			}
			else if(a[i].a>a[j].a){
				a[i].a-=a[j].a;
				j--;
			}
			else if(a[i].a<a[j].a){
				a[j].a-=a[i].a;
				i++;
			}
		}
		else {
			if(a[i].a==a[j].a){
				ans+=a[i].a;
				i++;
				j--;
			}
			else if(a[i].a>a[j].a){
				ans+=a[j].a;
				a[i].a-=a[j].a;
				j--;
			}
			else if(a[i].a<a[j].a){
				ans+=a[i].a;
				a[j].a-=a[i].a;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
