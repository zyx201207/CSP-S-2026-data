#include<bits/stdc++.h>
using namespace std;
int a[500005],num[500005],n,m;
bool b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
//	for(int t=1;t<=n;t++){
//		int top=0,s[500005];
//		for(int i=t;i<=n;i++){
//			if(!b[i]){
//				b[i]=1;
//				top++;
//				s[top]=a[i];
//			}else{
//				int ni;
//				for(int j=1;i<=top;i++){
//					if(a[i]==s[j]){
//						ni=j;
//					}
//				}
//				for(int j=ni;j<=top;j++){
//					b[s[j]]=0;
//					s[j]=0;
//				}
//				top=ni;
//				s[top]=a[i];
//			}
//		}
//		for(int i=t;i<=top;i++){
//			num[s[i]]++;	
//		}
//	}
	for(int i=1;i<=n;i++){
		num[a[i]]=i; 
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
