#include<iostream>
using namespace std;
long long x[500009],y[300009]={ },ans[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b,w=0;
	cin >> a>> b;
	for(int q=1;w<a;q++){
		w++;
		cin >> x[q];
		int g=x[q];
		y[x[q]]++;
		if(y[x[q]]>=2){
			y[x[q]]=1;
			x[q]=0;
			while(x[q]!=g){
				x[q]=0;
				q--;
			}
		}
		long long n=1;
		while(x[n]!=0){
			ans[x[n]]++;
			n++;
		}
	}
	long long l=1;
	while(ans[l]!=0){
		cout << ans[l]<<" ";
		l++;
	}
	return 0;
}
