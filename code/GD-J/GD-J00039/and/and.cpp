#include<iostream>
#include<algorithm>
using namespace std;

struct Num{
	int val;
	int d;
}; 

const int MAXN=2e5+5;

int n,m,ans;
Num a[MAXN]; 

int dig(int x){
	int res=0;
	while(x){
		if(x&1){
			res++;
		}
		x>>=1;
	}
	return res;
} 

bool cmp(Num a,Num b){
	if(a.d==b.d){
		return a.val>b.val;
	}
	return a.d>b.d;
}

void debug(){
	for(int i=1;i<=n;i++){
		cout<<a[i].val<<" ";
	}
	cout<<endl;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
//	cout<<dig(n);
	bool special_characteristic_B=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
		if(a[i].val!=i-1){
			special_characteristic_B=0;
		}
		a[i].d=dig(a[i].val);
	}
	
//	cout<<special_characteristic<<endl;

	if(special_characteristic_B){
		cout<<n-m<<'\n';
		return 0;
	}
	
	sort(a+1,a+n+1,cmp); 
//	debug();
	ans=a[1].val;
	for(int i=2;i<=m;i++){
		ans=ans&a[i].val;
	}
	
	cout<<ans<<'\n';
	

	
	return 0;
}
