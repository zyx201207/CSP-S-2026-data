#include<bits/stdc++.h>

using namespace std;
long long n,m,a[500010],s,b[500010],bj;//stack
//stack<p> q;
//struct p{
//	long long k,xb;
//}t[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		b[i]=a[i];
	}
	if(n==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) {
				cout<<1;
				return 0;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			b[j]=a[j];
//			t[j].k =a[j];t[j].xb =j;
//		}
//		for(int f=i;f<=n;f++){
//			
//			if(!q.empty()){
//				for(int l=0;l<q.size();l++){
//					if(t[f].k ==t[l].k ){
////						auto it=q.find(q.begin()+l,q.end(),t[])
//						for(int w=q.size()-1;w>=l;w--){
//							q.pop();
//						}
//						
//					}
//				}
//			}
//			q.push(t[f]);
//		}
//		
//	}
	
	return 0;
}
