#include<bits/stdc++.h>
using namespace std;
struct innt{
	long long sum;
	char a;
}a[1234567];
long long n,num;
string l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum;
	for(long long i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].a;
		sum+=a[i].sum;
	}
	sum/=2;
	long long cnt=sum;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].sum;j++){
			l+=a[i].a;
			cnt--;
			if(cnt==0)break;
		}
		if(cnt==0)break;
	}
	cnt=sum;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=a[i].sum;j++){
			r+=a[i].a;
			cnt--;
			if(cnt==0)break;
		}
		if(cnt==0)break;
	}
	//cout<<l<<"\n"<<r<<"\n";
	for(int i=0;i<sum;i++){
		if(l[i]!=r[i])num++;
	}
	cout<<num;
}
/*struct innt{
	long long sum;
	char a;
}a[1234567],r[1234567],l[1234567];
bool cmp(innt x,innt y){
	return x.a<y.a;
}
long long n,sum,cnt,num,l_len,r_len;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].a;
		sum+=a[i].sum;
	}
	sum/=2,num=sum;
	for(int i=1;i<=n;i++){
		if(num==0)break;
		if(a[i].sum<=num){
			l[++l_len].sum=a[i].sum,l[l_len].a=a[i].a,num-=a[i].sum;
		}
		else{
			l[++l_len].sum=num,l[l_len].a=a[i].a;
			break;
		}
	}
	
	num=sum;
	for(int i=n;i>=1;i--){
		if(num==0)break;
		if(a[i].sum<=num){
			r[++r_len].sum=a[i].sum,r[r_len].a=a[i].a,num-=a[i].sum;
		}
		else{
			r[++r_len].sum=num,r[r_len].a=a[i].a;
			break;
		}
	}
	
	sort(r+1,r+1+r_len,cmp);
	sort(l+1,l+1+l_len,cmp);
	for(int i=1;i<=l_len;i++){
		cout<<l[i].sum<<" "<<l[i].a<<"\n";
	}
	cout<<"\n";
	for(int i=1;i<=r_len;i++){
		cout<<r[i].sum<<" "<<r[i].a<<endl;
	}
	int i=1,j=1;
	while(1){
		if(i>sum)
		if(l[i].a==r[j].a){
			if(l[i].sum>r[j].sum)l[i].sum-=r[j].sum,j++;
			else if(l[i].sum==r[j].sum)i++,j++;
			else r[j].sum-=l[i].sum,i++;
		}
		else if(l[i].sum<r[j].sum){
			cnt+=l[i].sum;
			i++;
		}
		else{
			cnt+=r[i].sum;
			j++;
		}
	}
	cout<<
}*/
