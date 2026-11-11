#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
long long n,m,a[MAXN],ans,step;
long long ddu(){
	long long j=1;
	for(long long i=m;i>=0;){
		i=i-j*step;
		j++;
	}
	return j;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n+1);
	
	step=a[2]-a[1];
	cout<<ddu()-1;
	return 0;
	}


//10 2
//1 2 3 4 5 6 7 8 9 10
//2

//10 5
//2 4 6 8 10 12 14 16 18 20
//2

//1 2 3 4 2 3 1 4 2 2
//1 1 2 2 2 2 3 3 4 4
//1 0 2 0 0 0 3 0 4 0
//6

