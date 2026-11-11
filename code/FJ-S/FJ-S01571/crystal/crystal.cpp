#include<bits/stdc++.h>
using namespace std;
struct s1{
	long shu;
	long cha1;
	long cha2;
	long sum;
}a[500010];
bool cmp(s1 i1,s1 i2){
	return i1.sum<i2.sum;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,qi2=1;
	long long m,num,nun,qi[500010];
	bool qi3=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>qi[i];
	}
	sort(qi+1,qi+n+1);
	a[1].shu=qi[1];
	for(int i=2;i<=n;i++){
		if(qi[i]!=qi[i-1]){
			qi2++;
			a[qi2].shu=qi[i];
		}
		else{
			a[qi2].cha2++;
		}
	}
	for(int i=1;i<=qi2;i++){
		a[i].cha2++;
	}
	a[1].cha1=0;
	for(int i=2;i<=qi2;i++)
	{
		if(a[i].shu!=a[i-1].shu){
			a[i].cha1=a[i].shu-a[i-1].shu;
		}
		else{
			a[i].cha1=a[i-1].cha1;
		}
	}
	for(int i=2;i<=n-1;i++){
		if(a[i].cha1!=a[i+1].cha1){
			qi3=false;
			break;
		}
	}
	if(qi3==true){
		nun=m/a[2].cha1;
		cout<<nun<<endl;
		return 0;
	}
	a[1].sum=a[1].cha2;
	for(int i=2;i<=qi2;i++){
		num=m,nun=0;
		for(int j=i-1,k;j>=1;j--){
			nun+=a[j].cha1;
			k=num/nun;
			if(k==0){
				break;
			}
			else{
				a[i].sum+=k;
				if(k==1){
					break;
				}
			}
		}
		a[i].sum+=a[i].cha2;
		if(a[i].sum==n){
			cout<<a[i].sum<<endl;
			return 0;
		}
	}
	sort(a+1,a+qi2+1,cmp);
	cout<<a[qi2].sum<<endl;
	return 0;
}