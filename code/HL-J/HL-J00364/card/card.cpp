#include<bits/stdc++.h>
using namespace std;
int a[500010],c[300010],d[500010],ans[500010];
bool b[300010];
stack<int> s;
int main(){
	int n,m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
//		memset(s,false,sizeof(s));
		while(!s.empty()){
			s.pop();
		}
		for(int j=i;j<=n;j++){
			while(b[a[j]]){
				b[s.top()]=false;
				s.pop();
			}
			s.push(a[j]);
			b[a[j]]=true;
		}
//		while(!s.empty()){
//			c[s.top()]++;
//			s.pop();
//		}
		for(int j=1;j<=m;j++){
			if(b[j]){
				c[j]++;
				b[j]=false;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}


//	for(int i=n;i>=1;i--){
//		if(b[a[i]]){
//			for(int j=i;j<c[a[i]];j++){
//				d[j]-=i;
//				b[a[j]]=false;
//			}
//			d[i]=0;
//		}else{
//			d[i]=i;
//		}
//		b[a[i]]=true;
//		c[a[i]]=i;//¼ÇÂ¼i
//	}
//	for(int i=n;i>=1;i--){
//		ans[a[i]]=max(ans[a[i]],d[i]);
//	}
//	for(int i=1;i<=m;i++){
//		cout<<ans[i]<<" ";
//	}
	return 0;
}
