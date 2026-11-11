#include<bits/stdc++.h>
using namespace std;
stack<int> s;
const int N=3e5+10;
int a[N],sft[N],stt[N];
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(sft,0,sizeof sft);
		for(int j=i;j<=n;j++){
			s.push(a[j]);
			sft[a[j]]++;
			if(sft[a[j]]==2){
				while(sft[a[j]]!=0){
					sft[s.top()]--;s.pop();
				}
				s.push(a[j]);
				sft[a[j]]++;
			}
		}
		while(!s.empty()){
			int k=s.top();
			stt[k]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",stt[i]);
	return 0;
} 
