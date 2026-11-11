#include<bits/stdc++.h>
using namespace std;
struct str{
	int v;
	char c;
}li[200010];
int n;
long long cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>li[i].v>>li[i].c;
	}
	int i=1,j=n;
	while(i<j){
		int k=min(li[i].v,li[j].v);
		if(li[i].c!=li[j].c){
			cnt+=k;
		}
		if(li[i].v>li[j].v){
			j--,li[i].v-=k;
		}
		else{
			i++,li[j].v-=k;
		} 
	}
	cout<<cnt;
	return 0;
}
