#include<bits/stdc++.h>
using namespace std;
unsigned long long a[300005],n,ans,fst=1,lst;
char c[300005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	lst=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(fst=1;fst<lst;){
		if(c[fst]==c[lst]){
			if(a[fst]>a[lst]){
				a[fst]-=a[lst];
				a[lst]=0;
				lst--;
			}
			else if(a[fst]<a[lst]){
				a[lst]-=a[fst];
				a[fst]=0;
				fst++;
			}
			else{
				a[fst]=a[lst]=0;
				fst++;
				lst--;
			}
		}
		else{
			if(a[fst]>a[lst]){
				a[fst]-=a[lst];
				ans+=a[lst];
				a[lst]=0;
				lst--;
			}
			else if(a[fst]<a[lst]){
				a[lst]-=a[fst];
				ans+=a[fst];
				a[fst]=0;
				fst++;
			}
			else{
				ans+=a[fst];
				a[fst]=a[lst]=0;
				fst++;
				lst--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
