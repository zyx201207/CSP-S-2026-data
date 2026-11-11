#include<bits/stdc++.h>
using namespace std;
long long qzh[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool gdx = 0,gdy = 0;
	long long n = 0,b[200000],l,r,sum = 0,kk = 0;
	char a[200000],x,y;
	int t;
	cin >> t;
	for(int i = 0;i < t;i++){
		cin >> b[i] >> a[i];
		if(i){
			qzh[i] = qzh[i-1] + b[i];
		}
		else{
			qzh[0] = b[0];
		} 
		n += b[i];
	}
	if(n % 2){
		l = n/2;
		r = l+2;
		for(int i = 0;i < n/2;i++){
			int xy = 0;
			gdx = 0;
			gdy = 0;
			for(int j = 0;j < t;j++){
				if(l <= qzh[j] && !gdx){
					x = a[j];
					gdx = 1;
				}
				if(r <= qzh[j] && !gdy){
					y = a[j];
					gdy = 1;
				}
				if(gdx && gdy){
					break;
				}
			}
			if(!(x == y)){
				sum++;
			}
			l--;
			r++;
		}
		cout << sum; 
	}
	else{
		l = n/2-1;
		r = l+1;
		for(int i = 0;i < n/2;i++){
			kk = 0;
			int xy = 0;
			gdx = 0;
			gdy = 0;
			for(int j = 0;j < t;j++){
				if(l <= qzh[j] && !gdx){
					x = a[j];
					gdx = 1;
				}
				if(r <= qzh[j] && !gdy){
					y = a[j];
					gdy = 1;
				}
				if(gdx && gdy){
					break;
				}
			}
			if(!(x == y)){
				sum++;
			}
			l--;
			r++;
		}
		cout << sum; 
	}
	return 0;
}
