#include <bits/stdc++.h>
using namespace std;
long long n,m,c[200010],max1=-9999999999,egg=2147483647,max2=2147483647,max3=-9999999999,pk,pcz,d[200010],m1,d1=1;
int zuobiao;
long long andone(long long a,long long b){
	long long peng=1,ans=0;
	while(a>0&&b>0){
		if(a%2==1&&b%2==1){
			ans += peng;
		}
		a/=2;
		b/=2;
		peng*=2;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	m1=m;
	for(int i=1;i<=n;i++){
		cin >> c[i];
		max1 = max(max1,c[i]);
	}
	if(n==1){
		cout << c[1];
		return 0;
	}
	if(m==1){
		cout << max1;
		return 0;
	}else if(m==n){
		egg = c[1];
		for(int i=2;i<=n;i++){
			egg = andone(egg,c[i]);
		}
		cout << egg;
		return 0;
	}
	while(max1>0){
		max1=max1/2;
		pk++;
	}
	pk--;
	while(true){
		long long bijiao = 1;
		pcz=0;
		for(int i=1;i<=pk;i++){
			bijiao*=2;
		}
		for(int i=1;i<=n;i++){
			if(c[i] > bijiao && c[i]<=bijiao*2){
				pcz++;	
				max2 = andone(max2,c[i]);
			}
		}
		if(pcz>=m) break;
		else{
			pk--;	
			max2=2147483647;
			m1-=pcz;
		} 
	}
	long long bijiao1 = 1;
	for(int i=1;i<=pk;i++){
		bijiao1*=2;
	}
	for(int i=1;i<=n;i++){
		if(c[i] > bijiao1 && c[i]<=bijiao1*2){
			d[d1] = c[i];
			d1++;
		}
		if(c[i] > bijiao1*2 && c[i] <= bijiao1*4){
			if(c[i] % 2 == 0) d[d1] = c[i] / 2;
			else d[d1] = c[i]/2+1;
			d1++;
		}
	}
	for(int i=1;i<=m1;i++){
		max3=-9999999999;
		for(int j=1;j<=d1;j++){
			if(d[j] > max3){
				max3=d[j];
				zuobiao = j;
			}	
		}
		egg = andone(egg,max3);
		d[zuobiao] = -9999999999;
	}
	cout << egg;
	return 0;
} 
