#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
long long n , Long[M] , I , J , Ic , Jc , ans;
char a[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>Long[i]>>a[i];
		Long[i]+=Long[i-1];
	}
	I=1;  J=n;
	while(I<J){
		Ic=Long[I]-Long[I-1];
		Jc=Long[J]-Long[J-1];
		if(a[I]!=a[J])  ans+=min(Ic , Jc);
		if(Ic<Jc){
			Long[J]-=Ic;
			I++;
		}
		else if(Ic>Jc){
			Long[I-1]+=Jc;
			J--;
		}
		else {
			I++;
			J--;
		}
	}
	cout<<ans;
	
	return 0;
}
