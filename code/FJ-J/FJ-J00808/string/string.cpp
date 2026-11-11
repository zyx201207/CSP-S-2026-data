#include<bits/stdc++.h>
using namespace std;
long long n;
struct zifuchuan{
	long long a;
	char b;
}zfc[200005],z[200005],z2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long s=0;
	for(int i=1;i<=n;i++){
		cin>>zfc[i].a>>zfc[i].b;
		s+=zfc[i].a;
	}
	long long cnt=1,sum=zfc[1].a;
	bool flag=false;
	if(zfc[1].a>=s/2){
		z[cnt].a=s/2;
		z[cnt].b=zfc[1].b;
		cnt++;
		z[cnt].a=zfc[1].a-s/2;
		z[cnt].b=zfc[1].b;
		flag=true;
	}else{
		z[1].a=zfc[1].a;
		z[1].b=zfc[1].b;
	}
	for(int i=2;i<=n;i++){
			sum+=zfc[i].a;
			if(sum>=s/2&&!flag){
				if(z[cnt].b==zfc[i].b){
					z[cnt].a+=zfc[i].a-(sum-s/2);
					cnt++;
					z[cnt].b=zfc[i].b;
					z[cnt].a+=sum-s/2;
				}else{
					cnt++;
					z[cnt].a=zfc[i].a-(sum-s/2);
					z[cnt].b=zfc[i].b;
					cnt++;
					z[cnt].b=zfc[i].b;
					z[cnt].a=sum-s/2;
				}
				flag=true;
			}else{
				if(z[cnt].b==zfc[i].b){
					z[cnt].a+=zfc[i].a;
				}else{
					cnt++;
					z[cnt].b=zfc[i].b;
					z[cnt].a=zfc[i].a;
				}
			}
	}
	if(s%2!=0){
		long long s2=0;
		for(int i=1;i<=cnt;i++){
			s2+=z[i].a;
			if(s2>s/2){
				z[i].a--;
				break;
			}
		}
		long long sum=0;
		for(int i=1;i<=cnt;i++){
			if(z[i].a==0){
				continue;
			}
			sum++;
			z2[sum].a=z[i].a;
			z2[sum].b=z[i].b;
		}
		cnt=sum;
		for(int i=1;i<=sum;i++){
			z[i]=z2[i];
		}
	}
	long long sum2=0;
	for(int i=1,j=cnt;i<j;){
		if(z[i].b==z[j].b){
			if(z[i].a>z[j].a){
				z[i].a-=z[j].a;
				j--;
			}else if(z[i].a<z[j].a){
				z[j].a-=z[i].a;
				i++;
			}else{
				j--;
				i++;
			}
		}else{
			sum2+=min(z[i].a,z[j].a);
			if(z[i].a>z[j].a){
				z[i].a-=z[j].a;
				j--;
			}else if(z[i].a<z[j].a){
				z[j].a-=z[i].a;
				i++;
			}else{
				i++;
				j--;
			}
		}
	}
	cout<<sum2;
	return 0; 
}
