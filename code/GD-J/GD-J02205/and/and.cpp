#include<iostream>
#include<algorithm>
using namespace std;


bool c[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	long long a[200005]={0},maxand=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}for(long long i=1;i<n;i++){
		long long an=a[i]; 
		for(long long j=i+1;j<n;j++){
			if(c[j]){
				c[j]=false;
				an&=a[j];
			}else{j--;}
		}if(an>maxand){
			maxand=an;
		}
	}cout<<maxand;
	return 0;
}
