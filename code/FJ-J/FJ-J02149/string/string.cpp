#include<bits/stdc++.h>
using namespace std;
int n,a[200003],l,r,w,y,e,d,b,p;
char c[200003],sum[20];

void sus(int t){
	p=1;
	y=t;
	e=1;
	while(d==0||(sum[e]>='0'&&sum[e]<='9')||y!=0||w!=0){
		int s=max(int(sum[e]-'0'),0);
		if(d==0&&sum[e]!='0'&&sum[e]!='1'&&sum[e]!='2'&&sum[e]!='3'&&sum[e]!='4'&&sum[e]!='5'&&sum[e]!='6'&&sum[e]!='7'&&sum[e]!='8'&&sum[e]!='9'){
			b=e-1;
			d=1;
		}
		s=s+y%10+w;
		if(s>=10){
			w+=s/10;
			s%=10;
		}
		sum[e]=char(s+'0');
		y/=10;
		e+=1;
	}
	e=0;
	d=0;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	while(r>=l){
		if(l==r){
			break;
		}
		else if(l!=r){
			if(a[l]>a[r]){
				if(c[l]==c[r]){
					a[l]=a[l]-a[r];
					a[r]=0;
					r--;
				}
				else{
					sus(a[r]);
					a[l]=a[l]-a[r];
					a[r]=0;
					r--;
				}
			}
			else if(a[l]<a[r]){
				if(c[l]==c[r]){
					a[r]=a[r]-a[l];
					a[l]=0;
					l++;
				}
				else{
					sus(a[l]);
					a[r]=a[r]-a[l];
					a[l]=0;
					l++;
				}
			}
			else if(a[l]==a[r]){
				if(c[l]==c[r]){
					a[r]=0;
					a[l]=0;
					l++;
					r--;
				}
				else{
					sus(a[l]);
					a[r]=0;
					a[l]=0;
					l++;
					r--;
				}
			}
		}
	}
	if(p==1){
		for(int i=max(b-1,1);i>=1;i--){
			cout<<sum[i];
		}
	}
	else{
		cout<<"0";
	}
	return 0;
}
