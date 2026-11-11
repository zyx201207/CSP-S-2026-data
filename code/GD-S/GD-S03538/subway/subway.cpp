#include<bits/stdc++.h>
using namespace std;
long long n,m,a[700000],in[200000],in1[200000],p[7000],d,q,m1,x,y,b[7000][7000];
void f(){
	queue<long long>w,s1;
	for(int j=0;j<m;j++){
		if(b[x][j]!=0){
			w.push(j);
			p[j]=1;
			s1.push(b[x][j]);
		}
	}
	long long t,k,s=0;
	while(!w.empty()){
		t=w.front();
		k=s1.front();
		w.pop();
		s1.pop();
		for(int j=0;j<m;j++){
			if(t==y){
				cout<<a[x]+a[y]+k<<endl;
				return;
			}
			if(b[t][j]!=0){
				w.push(j);
				s1.push(k+b[t][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>m1;
		for(int j=0;j<m1;j++){
			cin>>in[j]>>in1[j];
		}
		for(int j=0;j<m1;j++){
			for(int k=0;k<m1;k++){
				if(k!=j){
					if(b[in[j]][in[k]]==0)b[in[j]][in[k]]=1e18;
					b[in[j]][in[k]]=min(b[in[j]][in[k]],in1[j]+in1[k]);
					if(b[in[k]][in[j]]==0)b[in[k]][in[j]]=1e18;
					b[in[k]][in[j]]=min(b[in[k]][in[j]],in1[j]+in1[k]);
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		memset(p,0,sizeof(p));
		f();
	}
	return 0;
}
