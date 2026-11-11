#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct {
    char c;
	long long cnt;	
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char c1;
	long long l=0,z=0;
	cin>>a[0].cnt>>a[0].c;
	for(int i=1;i<n;i++){
		cin>>l;
		cin>>c1;
		if(c1==a[z].c){
			a[z].cnt += l;
		}
		else{
			z++;
			a[z].cnt = l;
			a[z].c = c1;
		}
	}
	for(int i=0;i<z;i++){
		if(a[i].c != a[z-i].c){
			if(a[i].cnt==a[z-i].cnt){
				a[z-i].c=a[i].c;
				ans+=a[z-i].cnt; 
			}
			else if(a[i].cnt<a[z-i].cnt ){
				ans+=a[i].cnt;
				a[z-i].cnt-=a[i].cnt;
				z++;
			}
			else if(a[i].cnt>a[z-i].cnt ){
				a[z-i].c=a[i].c;
				ans+=a[z-i].cnt;
				a[i].cnt-=a[z-i].cnt;
				i--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
