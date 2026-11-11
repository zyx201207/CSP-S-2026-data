//GZ-S00202 贵阳市第一中学 薛子彦
#include<iostream>
using namespace std;
long long d,x[2000010],v[2000010],q[2000010],lv[200010];
int n,qh=0,qt=0;
int bfs(int a){
	//cout<<"BFSing "<<a<<endl;
	for(int i=1;i<=n;i++) v[i]=lv[i]=q[i]=0;
	qh=qt=0;
	q[qt++]=a;
	lv[a]=1;
	v[a]++;
	while(qh<qt){
		int h=q[qh++];
		int l=lv[h];
		//cout<<"Head:"<<h<<",Lv"<<l<<endl;
		int i=h+1;
		while(x[i]-x[h]<=d && i<=n){
			if(lv[i]==0 || lv[i]==l+1){
				q[qt++]=i;
				lv[i]=l+1;
				v[i]++;
			}
			i++;
		}
		/*
		cout<<"Hidx & Tidx:"<<qh<<' '<<qt<<endl<<"Queue:";
		for(int i=qh;i<qt;i++) cout<<q[i]<<' ';
		cout<<endl<<"Vis:";
		for(int i=1;i<=n;i++) cout<<v[i]<<' ';
		cout<<endl<<"Lvs:";
		for(int i=1;i<=n;i++) cout<<lv[i]<<' ';
		cout<<endl;
		*/
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i!=a && v[i]==2){
			cnt++;
		}
	}
	//cout<<"Count:"<<cnt<<endl;
	if(cnt) return cnt;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			/*
			int b=bfs(i);
			cout<<"Result "<<i<<":"<<b<<endl;
			ans+=b;
			*/
			ans+=bfs(i);
		}
		//cout<<"Final answer:"<<ans<<endl;
		cout<<ans<<endl;
	}
	return 0;
}

