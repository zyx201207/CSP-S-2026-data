//GZ-J00607 刘祚诚 北京师范大学贵阳附属中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
char a[N];
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0,w=1,ans=0;
	for(int i=1;i<=n;i++){
		int b;
		char c;
		cin>>b>>c;
		for(int j=1;j<=b;j++){
			a[w]=c;
			w++;
		}
		sum+=b;
	}
	for(int i=1,j=sum;i<=j;i++,j--){
		if(a[i]!=a[j])ans++;
	}
	cout<<ans<<endl;
	return 0;
}

