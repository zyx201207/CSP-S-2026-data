#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	long long a[n+1],t[n+1],maxn=0; int cnt=0; bool f=0; 
	for(int i=1;i<=n;i++){
		cin >> a[i];
		t[i]=a[i];
		maxn=max(maxn,a[i]);
	}
	while(maxn>1){
		maxn/=2;
		cnt++;
	}
	int x[n+1][cnt+5]; memset(x,0,sizeof(x));
	for(int i=1;i<=n;i++){
		int temp=a[i],d=0;
		while(temp>1){
			x[i][d++]=temp%2;
			temp/=2;
		}
	}
	for(int i=cnt;i>=1;i--){
		int p=0;
		for(int j=1;j<=n;j++){
			if(x[i][j]){
				p++;
				v.push_back(j);
			}
		}
		if(p<m){
			v.clear();
		}else if(p==m){
			long long sum=a[v[0]];
			for(int i=1;i<v.size();i++){
				sum=sum&a[v[i]];
			}
			cout << sum << "\n"; f=1;
			return 0;
		}
	}
	if(!f){
		bool flag=0; long long maxn1=0;
		for(int j=1;j<=n;j++){
			if(!flag&&t[j]==maxn){
				t[j]=0;
				flag=1;
			}
			maxn1=max(maxn1,t[j]);
		}	
		long long q=maxn&maxn1;
		cout << q << "\n";
	}
	return 0;
}
