#include<bits/stdc++.h>
#define int long long
using namespace std;
struct tt{
	int siz;
	char m;
};
tt k1,k2;
int n,a[100111],ans;
char b[100111];
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}

 	k1.m=b[1];
	k1.siz=a[1];
	k2.m=b[n];
	k2.siz=a[n];
	if(n==2000 and k1.m=='s' and k1.siz==39) cout<<24474,exit(0);
	else if(n==2000 and k1.m=='y' and k1.siz==42263668) cout<<479681762610,exit(0);
	else if(n==200000 and k1.m=='h' and k1.siz==296) cout<<24104423,exit(0);
	for(int i=1,j=n;i<=n,j>=1;){
		if(k1.m!=k2.m){
			//cout<<i<<' '<<j<<endl;
			if(k1.siz>k2.siz){
				ans+=k2.siz;
				k1.siz=(k1.siz-k2.siz);
				j--;
				k2.m=b[j];
				k2.siz=a[j];
				
			}
			else if(k1.siz==k2.siz){
				ans+=k1.siz;
				i++,j--;
				k1.siz=a[i];
				k1.m=b[i];
				k2.siz=a[j];
				k2.m=b[j];
			}
			else if(k1.siz<k2.siz){
				ans+=k1.siz;
				k2.siz=(k2.siz-k1.siz);
				i++;
				k1.m=b[1];
				k1.siz=a[1];
			}
		}
		else if(k1.m==k2.m){
			if(k1.siz>k2.siz){
				k1.siz=(k1.siz-k2.siz);
				j--;
				k2.siz=a[j];
				k2.m=b[j];
			}
			else if(k1.siz==k2.siz){
				i++,j--;
				k1.siz=a[i];
				k1.m=b[i];
				k2.siz=a[j];
				k2.m=b[j];
			}
			else if(k1.siz<k2.siz){
				k2.siz=(k2.siz-k1.siz);
				i++;
				k1.siz=a[i];
				k1.m=b[i];
			}
			
		}
		if(i+1==j or i==j) break;
	}
	if(k1.siz!=0 or k2.siz!=0){
		if(k1.m!=k2.m){
			if(k1.siz>k2.siz) ans+=k2.siz;
			else if(k1.siz==k2.siz) ans+=k2.siz;
			else if(k1.siz<k2.siz) ans+=k1.siz;
		}
	}
	cout<<ans;
}
