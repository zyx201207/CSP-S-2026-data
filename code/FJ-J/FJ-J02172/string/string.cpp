#include<bits/stdc++.h>
using namespace std;
char ci[200000];
int n,ai[200000];
long long run(){
	long long sum=0;
	int l=0,r=n-1;
	int lan=ai[l],ran=ai[r];
	while(l<r){
		if(lan>ran){
			if(ci[l]!=ci[r])
				sum+=ran;
			lan-=ran;
			ran=0;
		}else if(ran>lan){
			if(ci[l]!=ci[r])
				sum+=lan;
			ran-=lan;
			lan=0;
		}else{
			if(ci[l]!=ci[r])
				sum+=ran;
			lan=0;
			ran=0;
		}
		if(!lan)
			lan=ai[++l];
		if(!ran)
			ran=ai[--r];
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>ai[i]>>ci[i];
	cout<<run();
	return 0;
}

