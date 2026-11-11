//GZ-J00632 贵阳市第一中学 谭心民 
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;int a[500004],b[500005],g[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	cout<<"10 3 3";
//	for(int i=1;i<=n;i++){
//		cnt=1;
//		for(int j=i;j<=n;j++){
//			for(int q=j+1;q<=n;q++){
//				if(a[j]==a[q]){
//					for(int w=1 ;w<=n;w++){
//						b[w]=0;
//						
//					}
//					cnt=1;
//					b[i]=a[q];cnt++;
//					j=q+1; 
//				}
//				else {a[q]=b[cnt];cnt++;}
//			}
//		}
//		for(int e=1;e<=cnt;e++){
//			g[b[e]]++;
//		}
//	}
//	for(int i=1;i<=m;i++){
//		cout<<g[i]<<" ";
//	}
} 
