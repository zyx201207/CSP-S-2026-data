#include<bits/stdc++.h>
using namespace std;

struct w{
	long long start,stop;
	char world;
};

long long n,T=0,A,re=0,sear1,sear2;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	
	cin>>n;
	w a[n];
	for(long long i=0;i<n;i++){
		cin>>A>>a[i].world;
		a[i].start=T;
		a[i].stop=T+A-1;
		T+=A;
	}
	
	for(long long i=0;i<=T/2;i++){
		for(sear2=0;!(a[sear1].start<=i&&i<=a[sear1].stop)&&a[sear1].start<=T/2;sear1++)
		for(sear2=n-1;!(a[sear2].start<=T/2-i-1&&T/2-i-1<=a[sear2].stop)&&a[sear2].stop>=T/2;sear2--)
		
		if(a[sear1].world!=a[sear2].world)
			re++;
		else
			while(a[sear1].start<=i&&i<=a[sear1].stop&&a[sear2].start<=T/2-i-1&&T/2-i-1<=a[sear2].stop&&a[sear1].start<=T/2&&a[sear2].stop>=T/2&&i<=T&&T/2-i-1>=T)
				i++;
	}
	
	cout<<re;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
