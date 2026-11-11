#include <iostream>
#include <cstdio>
using namespace std;
int n,m,s;
int a[200005][31];
int fh[200005],mz,sm;
int num[31];
bool aand(int w){
	int g = 0;
	for(int i = 0;i < m;i ++){
		g += a[fh[i]][w];
	}
	if(g == m)
		return true;
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i ++){ 
		cin >> a[i][29];
		for(int j = 29;j > 0;j --){
			a[i][j - 1] = a[i][j] / 2;
			a[i][j] %= 2;
		}
	}
	for(int i = 0;i < 30;i ++){
		mz = 0;
		if(sm == 0){
			for(int j = 0;j < n;j ++){
				if(a[j][i] == 1)
					mz ++;
			}
		}
		else{
			for(int j = 0;j < sm;j ++){
				if(a[fh[j]][i] == 1)
					mz ++;
			}
		}
		if(mz < m && sm == 0){
			sm = 0;
			continue;
		}
		if(mz < m && sm >= m){
			mz = sm;
			break;
		}
		if(sm == 0){
			for(int j = 0,l = 0;j < n;j ++){
				if(a[j][i] == 1)
					fh[l ++] = j;
			}
		}
		else{
			for(int j = 0,l = 0;j < sm;j ++){
				if(a[fh[j]][i] == 1)
					fh[l ++] = fh[j];
			}
		}
		sm = mz;
		if(mz == m)
			break;
	}
	if(mz >= m){
		for(int i = 0;i < 30;i ++){ 
			if(aand(i))
				num[i] = 1;
			if(i != 0)
				num[i] += num[i - 1] * 2;
		}
		cout << num[29];
	}
	else
		cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
