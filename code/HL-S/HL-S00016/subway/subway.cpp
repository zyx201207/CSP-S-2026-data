//shapaoziAC
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
vector<long long>w;
class station{
	public:
		long long w;
		station(long long inw){
			w=inw;
		}
};
station* sta[130000];
class line{
	public:
		long long a[10000],t[10000];
		line(long long in_a,long long in_t,long long index_a,long long index_t){
			a[index_a]=in_a;
			t[index_t]=in_t;
		}
};
line* le[505];
fangan[100005][1];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		long long x=0;
		cin>>x;
		sta[i]=new station(x);
	}
	for(int i=0;i<n;i++){
		int k=0;
		cin>>k;
		int q=0,w=0,e=0,r=0;
		for(int j=0;j<2*k;j++){
			cin>>q>>w;
			le[i] = new line(q,w,e,r);
			e++;
			r++;
		}
	}
	for(int i=0;i<q;i++){
		cin>>fangan[i][0]>>fangan[i][1];
	}
	
	return 0;

}
//太难了，写不上了，算了吧