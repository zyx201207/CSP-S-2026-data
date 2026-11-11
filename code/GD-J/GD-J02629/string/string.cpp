#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans;
char c[200005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >> n;
	int flag=1,flag1=1,aa;
	char cc;
	for(int i = 0;i<n;i++){
		cin >>a[i]>>c[i];
		if(!i){
			cc=c[i];
			aa=a[i];
		}
		else{
			if(cc!=c[i])flag=0;
			if(aa!=a[i])flag1=0;
		}
	}
	if(flag){
		cout <<0;
		return 0;
	}if(flag1){
		int l=0,r=n-1;
		while(l<r){
			if(c[l]!=c[r])ans++;
			l++,r--;
		}cout << ans;
		return 0;
	}
	if(n==1){
		cout <<0;
	}else if(n<=2){
		if(a[0]>a[1])cout << a[1];
		else cout <<a[0];
	}else{
		int l=0,r=n-1,f[3]={0,0,0};
		long long q=0;
		char w;
		while(l<r){
			//cout << l<<' '<<r<<' '<<ans<<'\n';
			if(!f[0]){
				//cout << "!f————————\n";
				if(c[l]==c[r]){//c相同 
					q=a[l]-a[r];
					w=c[l],f[0]=1;
					if(q==0)f[0]=0;
					if(q>0)f[1]=1,f[0]=1;
					else f[2]=1,f[0]=1,q=-q;
				}else{//c不同 
					if(a[l]>a[r]){
						q=a[l]-a[r];
						w=c[l],ans+=a[r],f[1]=1;
						f[0]=1;
					}else{
						q=a[r]-a[l],w=c[r],f[2]=1;
						ans+=a[l];
						f[0]=1;
					}
				}
				if(f==0)r--,l++;
			}else{
				//cout << "f—————————\n";
				if(f[1]){//l多了 
					for(int i = r;i>l;i--){
						if(c[i]==w){//c同 
							if(a[i]<q){
								q-=a[i];
							}else if(a[i]>q){
								q=a[i]-q;
								f[0]=1,f[2]=1,f[1]=0;
								l++,r=i-1;
								break;
							}else{
								f[0]=0,f[1]=0,f[2]=0;
								q=0;
								l++,r=i-1;
								break;
							}
						}else{//c不同 
							if(a[i]<q){
								ans+=a[i];
								q-=a[i];
							}else if(a[i]>q){
								ans+=q;
								q=a[i]-q;
								w=c[i],f[0]=1,f[1]=0,f[2]=1;
								l++,r=i-1;
								break;
							}else {
								f[0]=0,f[1]=0,f[2]=0;
								ans+=q,q=0,l++,r=i-1;break; 
							}
						}
					}
					//cout << l<<' '<<r<<' '<<ans<<" 1\n";
				}else{//r多了 
					for(int i = l;i<r;i++){
						if(c[i]==w){//c同 
							if(a[i]<q){
								q-=a[i];
							}else if(a[i]>q){
								q=a[i]-q;
								f[0]=1,f[2]=0,f[1]=1;
								r--,l=i+1;
								break;
							}else{
								f[0]=0,f[1]=0,f[2]=0;
								q=0;
								r--,l=i+1;
								break;
							}
						}else{//c不同 
							if(a[i]<q){
								ans+=a[i];
								q-=a[i];
							}else if(a[i]>q){
								ans+=q;
								q=a[i]-q;
								w=c[i],f[0]=1,f[1]=1,f[2]=0;
								r--,l=i+1;
								break;
							}else {
								f[0]=0,f[1]=0,f[2]=0;
								ans+=q,q=0,r--,l=i+1;break; 
							}
						}
					}
					//cout << l<<' '<<r<<' '<<ans<<" 2\n";
				}
			}
		}cout <<ans;
	}
	return 0;
}
