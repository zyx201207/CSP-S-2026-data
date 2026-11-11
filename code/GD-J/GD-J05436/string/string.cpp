#include<iostream>
using namespace std;
long long a_t[200005];
char a_c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long ans = 0;
	for(long long i = 0;i < n;++i){
		cin>>a_t[i]>>a_c[i];
	}
	long long l=0,r=n-1;
	while(l<=r){
		if(a_c[l] != a_c[r] && a_t[l] > a_t[r]){
			ans+=a_t[r];
			r--;
			a_t[l]-=a_t[r];
		}
		if(a_c[l] != a_c[r] && a_t[l] < a_t[r]){
			ans+=a_t[l];
			l++;
			a_t[r]-=a_t[l];
		}
		if(a_c[l] == a_c[r] && a_t[l] > a_t[r]){
			a_t[l]-=a_t[r];
			r--;
		}
		if(a_c[l] == a_c[r] && a_t[l] < a_t[r]){
			a_t[r]-=a_t[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
