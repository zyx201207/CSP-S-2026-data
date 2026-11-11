#include<bits/stdc++.h>
using namespace std;
int n,a[200100];
long long midx,midy,qzh[200100];
long long len,s;
char c[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
		len+=a[i];
		qzh[i]=qzh[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(qzh[i]>=(len+1)/2){
			midx=i;
			midy=((len+1)/2)-qzh[i-1];
			break;
		}
	}
	int i=1,j=n,ii=a[1],jj=a[n];
	bool flag1,flag2;
	while(i<=j){
//		cout<<i<<" "<<j<<" "<<ii<<" "<<jj<<" "<<s<<endl;
		if(i==midx&&!flag1){
			if(len%2==0){
				ii=midy;
			}
			else{
				ii=midy-1;
			}
			flag1=true;
		}
		if(j==midx&&!flag2){
			if(len%2==0){
				jj=a[midx]-midy;
			}else{
				jj=a[midx]-midy+1;
			}
		}
		if(ii>jj){
			if(c[i]!=c[j]) s+=jj;
			ii-=jj;
			jj=a[j-1];
			j--;
		}
		else if(ii==jj){
			if(c[i]!=c[j]) s+=ii;
			ii=a[i+1];
			jj=a[j-1];
			i++;
			j--;
		}
		else if(ii<jj){
			if(c[i]!=c[j]) s+=ii;
			jj-=ii;
			ii=a[i+1];
			i++;
		}
//		cout<<i<<" "<<j<<" "<<ii<<" "<<jj<<" "<<s<<endl;
	}
	cout<<s<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}//9:31

