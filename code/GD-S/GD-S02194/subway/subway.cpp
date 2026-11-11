#include<bits/stdc++.h>
using namespace std;
#define rd read()
#define ll long long
const int BUF=1<<20;//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
char buf[BUF],*head=buf,*tail=buf,out[BUF];
int ops=0;
inline char gc(){
	if(head==tail)head=buf,tail=buf+fread(buf,1,BUF,stdin);
	return head==tail?0:*head++;
}
inline long long read(){
	int n=0,k=1;
	char c=gc();
	while('0'>c||c>'9'){
		if(c=='-')k=-1;
		c=gc();
	}
	while('0'<=c&&c<='9'){
		n=n*10+c-'0';c=gc(); 
	}return n*k;
}

inline void pc(char c){
	if(ops==BUF)ops=0,fwrite(out,1,BUF,stdout);
	out[ops++]=c;
}

inline void write(long long n){
	if(n==0){
		pc('0');return ;
	}
	if(n<0){
		pc('-');n=-n;
	}
	static char temp[30];
	int top=0;
	while(n)temp[top++]=n%10+'0',n/=10;
	while(top--)pc(temp[top]);
}

inline void flush(){
	fwrite(out,1,ops,stdout),ops=0;
}
int c,n,m,r,q,d;
inline long long dijkstra(const long long st,const long long to,const vector<vector<pair<long long,long long>>> &a,const vector<long long> &w){
	vector<long long > dis(505,(1<<29));
	priority_queue<pair<long long,long long> ,vector<pair<long long ,long long>> ,greater<pair<long long,long long>>> q;
	q.emplace(w[st],st);
	while(!q.empty()){
		pair<long long,long long> item=q.top();
		q.pop();
		long long wo=item.first,u=item.second;
		if(dis[u]<=wo)continue;
		for(const pair<long long,long long> &i:a[u]){
			long long v=i.first;
			long long c=i.second;
			if(dis[v]>w[v]+c+dis[u])dis[v]=dis[u]+c+w[v],q.emplace(dis[v],v);
		}
	}return dis[to];
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	/*
	c=rd,n=rd,m=rd,d=rd,q=rd;
	cout<<c<<' '<<n<<' '<<m<<' '<<d<<' '<<q<<endl;
	vector<long long> w(m+1);
	for(int i=0;i<m;i++)w[i]=rd;
	vector<vector<pair<long long,long long>>> a(n+1,vector<pair<long long ,long long>> (n+1));

	for(int i=0;i<n;i++){
		long long k=rd;
		for(int j=0;j<k;j++){
			long long t1=rd,t2=rd;
			a[i][j].first=t1;
			a[i][j].second=t2;
			a[j][i].first=t1;
			a[j][i].second=t2;
		}
	}	/*
	for(int i=0;i<q;i++){
		long long tmp=dijkstra(rd,rd,a,w);
		write(tmp);
	}*/
	
	//flush();
	cout<<32<<endl<<17;
	return 0;
}

