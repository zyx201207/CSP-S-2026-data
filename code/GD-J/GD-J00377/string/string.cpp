#include<iostream>
#include<cstdio>
using namespace std;
using ll=long long;
const int MN=200000+1;
ll Lens[MN]{0},L=0,Tot=0;
ll Abs(ll L){
	return (L<0)?-L:L;
}
ll Min(ll A,ll B){
	return (A>B)?B:A;
}
char Str[MN];
int ARLength=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int N;
	scanf("%d",&N);
	char U=' ';
	for(int I=1;I<=N;I++){
		ll X;char C;
		scanf("%lld %c",&X,&C);
		if(C==U)Lens[ARLength]+=X;
		else{
			ARLength++;
			Lens[ARLength]=X;
			Str[ARLength]=C;
		}
		L+=X;
		U=C;
	}
	for(int I=1;I<=ARLength/2;I++){
		if(Str[I]==Str[ARLength-I+1])Tot+=Min(Lens[I],Abs(Lens[ARLength-I+1]-Lens[I]));
		else Tot+=Min(Lens[I],Lens[ARLength-I+1]);
	}
	printf("%lld",Tot);
	return 0;
}
