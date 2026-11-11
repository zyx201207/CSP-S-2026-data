#include<bits/stdc++.h>
using namespace std;
//const int N=1e9+1;
int m;
long long sum=0;
vector<long long>a;
vector<char>c;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=1,j=m+1;;i++,j--){
		if(i==j) break;
		if(c[i]==c[j] && a[i]==a[j]){
			continue;
		}
		else if(c[i]!=c[j] && a[i]==a[j]){
			sum+=a[i];
			continue;
		}
		else if(c[i]==c[j] && a[i]!=a[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				i--;
				continue;
			}
			else{
				a[j]-=a[i];
				j++;
				continue;
			}
		}
		else{
			if(a[i]>a[j]){
				sum+=a[j];
				a[i]-=a[j];
				i--;
				continue;
			}
			else{
				sum+=a[i];
				a[j]-=a[i];
				j++;
				continue;
			}
		}
	}
	cout<<sum;
	return 0;
}
