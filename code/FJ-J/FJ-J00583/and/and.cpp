#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
int vis[200001];
struct node{
	int g;
	string sc;
}a[200001];
void er(long long z,int g){
	long long o=1;
	while(z!=0){
		if(z%2==1){
			a[g].sc+='1';
			vis[o]+=1;
		}else{
			a[g].sc+='0';
		}
		z/=2;
		o+=1; 
	}
	ans=max(ans,o);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].g;
		er(a[i].g,i);
		//cout<<a[i].sc<<endl;
	}
	for(int i=1;i<=ans;i++){
		cout<<vis[i]<<endl;
	}
	stack<int>s; 
	for(int i=ans;i>=1;i--){
		if(vis[i]==m){
			for(int j=1;j<=n;j++){
				if(a[j].sc[i]==1){
					s.push(j);
					cout<<j;
				}
			}
		}
	}
	int vvis[200001],lll=0;
	memset(vvis,1,sizeof(vvis));
	while(!s.empty()){
		int h=s.top();
		int ff=a[h].sc.size();
		lll=max(lll,ff);
		for(int i=1;i<=a[h].sc.size();i++){
			if(a[h].sc[i]=='0'){
				vvis[i]=0;
			}
		}
	} 
	long long cnt=0,f=1;
	for(int i=lll;i>=0;i--){
		if(vvis[i]==1){
			cnt+=f;
		} 
		f*=2;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

