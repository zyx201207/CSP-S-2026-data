#include<bits/stdc++.h>
using namespace std;
struct s{
	char c;
	int l;
}a[200010];
int n; 
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].l>>a[i].c;
	}
	for(int i=0,j=n-1;i<j;){
		if(a[i].l==a[j].l){
			if(a[i].c!=a[j].c){
				ans+=a[i].l;
				i++,j--;
			}
			else{
				i++,j--;
			}
		}
		else{
			if(a[i].c==a[j].c){
				if(a[i].l<a[j].l){
					a[j].l-=a[i].l;
					i++;
				}
				else{
					a[i].l-=a[j].l;
					j--;
				}
			}
			else{
				if(a[i].l<a[j].l){
					a[j].l-=a[i].l;
					ans+=a[i].l;
					i++;
				}
				else{
					a[i].l-=a[j].l;
					ans+=a[j].l;
					j--;
				}
			}
		}
		if(a[i].l==0) i++;
		if(a[j].l==0) j--;
	}
	cout<<ans;
	
	return 0;
}
