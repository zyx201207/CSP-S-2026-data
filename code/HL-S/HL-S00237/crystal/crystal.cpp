#include <bits/stdc++.h>
using namespace std;

int main(){

	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	long long a[500005];

	long long n,m,d,nums=0,s,t;
	cin>>n>>m;
	for(long long  i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
           d=a[2]-a[1];
           long long w=a[i]-a[i-1];
           if(d!=w){
            nums++;
            break;
              }

		}
	}
	sort(a+1,a+1+n);
if(nums!=0){

              for(long long h=1;h<=n;h++){
                  m=m-(h-1)*(a[h]-a[h-1]);
                  if(m<0){
                   t=h-1;
                    break;
                    }

                 }




                                 for(long long l=n;l>=1;l--){
                                     m=m-(a[l]-a[l-1])*(n-l);
                          if(m<0){
                                s=n-l;
                                break;
                                }
                                }




if(s>=t){cout<<s;return 0;}
else {cout<<t;return 0;}
}



if(nums==0){
        long long  s=a[2]-a[1];
		for(long long  j=1;j<=n;j++){

            m=m-(j-1)*s;
            if(m<0){
				cout<<j-1;

				return 0;
			}
		}
}

		return 0;
}
