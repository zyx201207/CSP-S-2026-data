#include<bits/stdc++.h>
using namespace std;
string e;
string v;
string t;
string w[200005];
string y[200005];
int mun = 0,f = 1,num = 0;
int main(){
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	for(int i = 1;i<=a;i++){
		int b;
		cin>>b;
		char c;
		cin>>c;
		
		for(int j = 1;j<=b;j++){
			e += c;
			w[f] = c;
			f++;
		}
	}
	int s = e.size();
	int q = 1;
	for(int i = s;i >= 1;i--){
		y[q] = w[i];
		q++;
	}
	for(int i = 1;i<=s;i++){
		if(w[i] != y[i]){
			mun++; 
		}
	}if(mun == 0){
		cout<<mun;
	}else{
		int h = s;
		for(int j = 1;j<=s;j++){
			num = 0;
			y[j] = w[j];
			w[h] = y[j];
			h--;
			for(int i = 1;i<=s;i++){
				if(w[i] != y[i]){
					num++; 
				}
			}
			if(num == 0){
				cout<<j;
				return 0;
			}
		}
	}
	return 0;
}



