#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],sum=0,num=0,x,t,yf,cnt,he=0,ans=0;
char c[200005];
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		num+=a[i];
		if(num>=sum/2){
			x=i;
			break;
		}
	}
	
	if(sum%2==1){
		if(num==sum/2){
			a[x+1]--;
		}else{
			t=num-sum/2-1;
			if(t==0){
				a[x]--;
			}else{
				yf=a[x];
				a[x]=t;
				n++;
				for(int i=n;i>x;i--){
					a[i]=a[i-1];
					c[i]=c[i-1];
				}
				a[x]=yf-t-1;
			}
		}
	}else{
		if(num>sum/2){
			t=num-sum/2;
			yf=a[x];
			a[x]=t;
			n++;
			for(int i=n;i>x;i--){
				a[i]=a[i-1];
				c[i]=c[i-1];
			}
			a[x]=yf-t;
		}
	}
	/*for(int i=1;i<=n;i++){
		cout<< a[i] << " " << c[i] << endl; 
	}*/
	cnt=n;
	for(int i=1;i<=n;i++){
		while(i<cnt && he<sum/2){
			if(c[i]==c[cnt]){
				if(a[i]>a[cnt]){
					he+=a[cnt];
					a[i]-=a[cnt];
					cnt--;
					continue;
				}else if(a[i]<a[cnt]){
					a[cnt]-=a[i];
					he+=a[i];
					break;
				}else{
					cnt--;
					he+=a[i];
					break;
				}
			}else{
				if(a[i]>a[cnt]){
					he+=a[cnt];
					ans+=a[cnt];
					a[i]-=a[cnt];
					cnt--;
					continue;
				}else if(a[i]<a[cnt]){
					a[cnt]-=a[i];
					he+=a[i];
					ans+=a[i];
					break;
				}else{
					cnt--;
					he+=a[i];
					ans+=a[i];
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
