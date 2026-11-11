#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int n,m,cnt[300005],cnrt[300005],a[500005],t[300005],c;
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		memset(cnt,0,sizeof(cnt));
		c=0;
		while(!s.empty()){
			s.pop();
		}
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]>0){
				while(!s.empty()&&s.top()!=a[j]){
					s.pop();
				}
			}else{
				while(!s.empty()){
					t[++c]=s.top();
					cnt[s.top()]++;
					s.pop();
				}
				for(int k=c;k>=1;k--){
					s.push(t[k]);
				}
				s.push(a[j]);
				cnt[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cnrt[i]+=cnt[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnrt[i]<<" ";	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
