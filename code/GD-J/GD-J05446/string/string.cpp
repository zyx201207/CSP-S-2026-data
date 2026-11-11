#include<bits/stdc++.h>
using namespace std;
long long a,s=1000000001,d=1,f,g=1,h,z1[200005];
char z[200005],x[200005];
int x1[100],x2[100];
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>a;
	for(int q=1;q<=a;q++){
		scanf("%d %c",&z1[q],&x[q]);
		s=min(z1[q],s);
	}
	if(s!=1)
	for(long long q=s;q>=1;q--){
		bool p=0;
		for(long long w=1;w<=a;w++){
			if(z1[w]%q!=0){
				p=1;
				break;
			}
		}
		if(p==0){
			for(long long w=1;w<=a;w++){
				z1[w]/=q;
			}
			d=q;
			break;
		}
	}
	for(long long q=1;q<=a;q++){
		for(long long w=f+1;w<=f+z1[q];w++){
			z[w]=x[q];
		}
		f+=z1[q];
	}
	long long p,p1;
	if(f%2==0){
		p=f/2,p1=f/2+1;
		for(long long q=1;q<=f/2-1;q++){
			if(z[p]!=z[p1]){
				g++;
			}
			p--;
			p1++;
		}
	}else {
		p=f/2,p1=f/2+2;
		for(long long q=1;q<=f/2-1;q++){
			if(z[p]!=z[p1]){
				g++;
			}
			p--;
			p1++;
		}
	}
	if(g==0){
		cout<<0;
		return 0;
	}
	for(int q=1;q<=20;q++){
		x1[q]=d%10;
		x2[q]=x1[q];
		d/=10;
	}
	for(int q=1;q<=g-1;q++){
		for(int w=1;w<=20;w++){
			x1[w]+=x2[w];
			if(x1[w]>=10){
				x1[w+1]++;
				x1[w]-=10;
			}
		}
	}
	bool o=0;
	for(int q=20;q>=1;q--){
		if(x1[q]!=0||o==1){
			o=1;
			cout<<x1[q];
		}
	}
	if(o==0)cout<<0;
} /*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
