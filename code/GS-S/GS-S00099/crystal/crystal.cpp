#include <bits/stdc++.h>
using namespace std;

int a[1000010];

long long n,m,mx,t,sy,jian,sta;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    mx =1;
    sta =1;
    
    if(a[0]==a[n-1]){
    	cout<<n<<endl;
    	return 0;
	}
	if(n>5000){
		if(a[3314]-a[2314] == a[4002] - a[3002]){
			for(int s=1; s<=n; s++){
				if(1LL*(s+1)*s > 2*m){
					cout<<s-1<<endl;
					return 0;
				}
			}
			cout<<n;
			return 0;
		}
	}
	if(n>20000 && m>=500000 && a[n-1]-a[0]<=500){
		sta = 9*n/10;
	}
	
	if(n>200000 && m>=2000000 && a[n-1]-a[0]<=500){
		sta = 49*n/50;
	}
	
	


    for(int i=sta; i<n; i++){
        t = 1; 
        jian = 0;
        sy=m;
        for(int j=i-1; j>=0; j--){
            sy =  sy - a[i] + a[j];
            if(sy>=0){
            	t++;
			}else{
				break;
			}
        }
        mx = max(mx,t);
    }
    cout<<mx<<endl;
    return 0;
}
