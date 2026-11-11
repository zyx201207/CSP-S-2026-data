#include<bits/stdc++.h>
using namespace std;
int n;
struct s{
	long long x;
	string c;
}a[100001];
string y,z;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		for(int j=1;j<=a[i].x;j++){
			y+=a[i].c;
		}
	}
	//cout<<y.size()<<" ";
	long long i=0,j=y.size()-1; 
	while(i<=j){
		if(y[i]!=y[j]){
			sum++;
		} 
		i++;j--;
	}
	cout<<sum;
	return 0;
}
