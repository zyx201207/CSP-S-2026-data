#include<iostream>
#include<algorithm>
using namespace std;
const int N = 200005;

int n;
int a[N];
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long ans = 0;
	int l=1,r = n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<r){
			int temp = min(a[l],a[r]);
			if(c[l]!=c[r])ans+=temp;
			a[l] = a[l]-temp;
			a[r] = a[r]-temp;
			if(!a[r])r--;
			if(!a[l])l++;
	}
	cout<<ans;
} 
