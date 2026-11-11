#include<bits/stdc++.h>//ÎÄ¼þ²Ù×÷ 
using namespace std;
struct s{
	long long sl;
	char zf;
}a[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].sl>>a[i].zf;
		sum+=a[i].sl;
	} 
	bool f=0;
	for(int i=2;i<=n;i++){
		if(a[i].zf!=a[i-1].zf) f=1;
	}
	if(f==0){
		cout<<0;
		return 0;
	}
	int o;
	if(sum%2==0) o=sum/2;
	else o=(sum+1)/2;
	cout<<sum-o;
	return 0;
} 
