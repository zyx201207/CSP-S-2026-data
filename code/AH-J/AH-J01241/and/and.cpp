#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long a[300000];
void nb(long long i,long long k,long long n,long long sum){
	if(k==0){
		if(sum>ans)ans=sum;
		return;
	}
	for(long long j=i+1;j<n;j++){
		nb(j,k-1,n,sum&a[j]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		nb(i,m-1,n,a[i]);
	}
	cout<<ans;
	return 0;
}


















/*#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	if(x>y)return true;
	else return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	int a[300000];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(m==1){
		cout<<a[0];
		return 0;
	}
	long long ans;
	m-=2;
	ans=a[0]&a[1];
	int j=2;
	while(m>0){
		ans=ans&a[j];
		j++;
		m--;
	}
	cout<<a[0]<<" "<<a[1]<<endl;
	cout<<ans;
	return 0;
}
//Trick||Treat!
*/
