#include <bits/stdc++.h>
using namespace std;
struct nn{
	long long num ;
	string c;
}a[200000] , b[20000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n ;
	cin >> n;
	long long t = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		t += a[i].num;
	}
	long long  z = 0 , j ,j1;
	for(int i = 1;i<=n;i++){
		z+= a[i].num;
		if(z>=t/2){
			j = i;
			j1 = z-t/2;
			break;
		}
	}
	long long j2 = j;
	long long tt=0;
	#define int long long 
	for(;j<=n;j++)
	{
		b[++tt].num=a[j].num;
		b[tt].c=a[j].c;
	}
	int v = b[1].num;
	b[1].num=j1;
	if(t%2!=0)b[1].num-=1;
	a[j2].num= v-j1;
	
	int cu = 0 ,x =1 , y = 1 ,ans =0;
	while(x<=j2&&y<=tt){
		if(a[x].c!=b[y].c){
			ans += min(a[x].num,b[y].num);
		}
		int gap =abs (a[x].num-b[y].num);
		if(a[x].num<b[y].num){
			while(gap>0){
				x++;
				gap-=a[x].num;
				if(a[x].c!=b[y].c) ans += abs(gap);
			}			
		}else if(a[x].num==b[y].num){
			x++;
			y++;
		}else {
			while(gap>0){
				y++;
				gap-=b[y].num;
				if(a[x].c!=b[y].c) ans += abs(gap);
			}				
		}
	}
	cout <<ans;
	return 0; 
} 
/*
9
39 s
8 r
31 e
35 c
39 x
26 c
12 a
23 d
4 g
a 1-j2
b 1-tt
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
