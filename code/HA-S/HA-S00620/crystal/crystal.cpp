//#include<bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//const int N=5e5+5;
//int con[N];
//ll n,m;
//
//int main(){
//	cin>>n>>m;
//	
//	return 0;
//}

//Æ­·Ö
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N];
ll n,m;
int find(int x){
	int l=1,r=n;
	int mid;
	while(l<r-1){
		mid=(l+r)/2;
		if((x*mid*mid-x*mid)/2==m)return mid;
		if((x*mid*mid-x*mid)/2<m)l=mid;
		else if((x*mid*mid-x*mid)/2>m)r=mid-1;
		else break;
	}
	return l;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int t=a[2]-a[1];
	cout<<find(t);
	
	return 0;
} 
