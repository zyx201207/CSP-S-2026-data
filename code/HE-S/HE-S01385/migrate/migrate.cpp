#include<bits/stdc++.h> 
using namespace std;
long long n,d,x[2000003],y[2000003]={},s[2000003]={};
void bfs(){
	queue<int>q;
	queue<int>p;
	q.push(1);
	p.push(0);
	while(q.size()){
		long long z=q.front(),i=1,e=p.front();
		while(i+z<=n&&x[z]+d>=x[z+i]){
			q.push(z+i);
			p.push(e+1);
			if(s[z+i]!=0&&s[z+i]==e+1){
				y[z+i]++;
			}else if(s[z+i]==0){
				y[z+i]++;
				s[z+i]=e+1;
			}
			i++;
		}
		q.pop();
		p.pop(); 
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		bfs();
		long long num=0;
		for(int j=1;j<=n;j++){
			if(y[j]==2){
				num++;
			}
			y[j]=0;
			s[j]=0;
		}
		cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
