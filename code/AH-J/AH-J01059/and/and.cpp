#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m;
	cin >> n >> m;
	long long a[n+5];
	long long x,y;
	long long maxans = 0;
	
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	
//m=2时
	for(long long i=1;i<n;i++){
		x = a[i];
		for(long long j=i+1;j<=n;j++){
			y = a[j];
			//进行按位与运算
			//x,y转二进制 
			long long x1[x+5];
			long long y1[y+5];
					string x2;
			string y2;
			long long xx = x;
			long long yy = y;
			long long xb1 = 1;
			long long j1 = 1;
			long long xb2 = 1;
			long long j2 = 1;
			while(xx>0){
				 x1[xb1] = xx%2;
				 xx/=2;
				 xb1++;
			}
			for(long long i=xb1;i>=1;i--){
				x2[j1] = x1[i];
				j1++;
			}
			while(yy>0){
				 y1[xb2] = yy%2;
				 yy/=2;
				 xb2++;
			}
			for(long long i=xb2;i>=1;i--){
				x2[j2] = x1[i];
				j2++;
			}
			//x,y按位与
			long long answer;
			for(i=0;i<min(xb1,xb2);i++){
				if(x2[xb1-i] == 1 && y2[xb2-i] == 1){
					answer += pow(2,i);
				}
			}
			if (answer > maxans){
				maxans = answer;
			}
		}
	} 
	cout << maxans;

		
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
