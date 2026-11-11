#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],n,s[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	long long x=1,y=s[n],xi=1,yi=n;
	int fl=1;
	if(s[n]%2==1){
		fl=2;
	}
	while(y-x>=fl){
		if(c[xi]==c[yi]){
			if(a[xi]==a[yi]){
				x+=a[xi];
				y-=a[yi];
				xi++;
				yi--;
			}
			else if(a[xi]<a[yi]){
				int cm=a[xi];
				while(cm<a[yi]){
					xi++;
					if(cm+a[xi]<=a[yi]){
						cm+=a[xi];
						if(c[xi]!=c[yi]){
							ans+=a[xi];
						}
					}else if(cm+a[xi]>a[yi]){
						a[xi]-=a[yi]-cm;
						if(c[xi]!=c[yi]){
							ans+=a[yi]-cm;
						}
						cm=a[yi];
					}
				}
				y-=a[yi];
				x+=cm;
				yi--;
				xi++;
			}		
			else if(a[xi]>a[yi]){
				int cm=a[yi];
				while(cm<a[xi]){
					yi--;
					if(cm+a[yi]<=a[xi]){
						cm+=a[yi];
						if(c[xi]!=c[yi]){
							ans+=a[yi];
						}
					}else if(cm+a[yi]>a[xi]){
						a[yi]-=a[xi]-cm;
						if(c[yi]!=c[xi]){
							ans+=a[xi]-cm;
						}
						cm=a[xi];
					}
				}
				y-=cm;
				x+=a[xi];
				yi--;
				xi++;
			}
		}
		else{
			if(a[xi]==a[yi]){
				x+=a[xi];
				y-=a[yi];
				ans+=a[yi];
				xi++;
				yi--;	
			}
			else if(a[xi]<a[yi]){
				ans+=a[xi];
				a[yi]-=a[xi];
				y-a[xi];
				x+=a[xi];
				xi++;
			}else{
				ans+=a[yi];
				a[xi]-=a[yi];
				x+=a[yi];
				y-=a[yi];
				yi--;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
5
1 a
2 b
1 x
1 b
2 a
*/
