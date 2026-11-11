#include<bits/stdc++.h>
using namespace std;
long long s[30]={},lon=1,addd;
long long n,l=0,l2,r=0,r2;
void add(int a){
	int ad=0;
	s[1]+=a;
	for(int i=2;i<=lon+1;i++){
		if(s[i-1]>=10){
			ad=s[i-1]/10;
			s[i-1]=s[i-1]%10;
			if(i==lon+1&&s[i]==0){
				lon++;
			}
		}
		s[i]+=ad;
		ad=0;
	}
}
struct ascll{
	long long id;
	char word;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ascll a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i].id>>a[i].word;
		addd+=a[i].id;
	}
	l=1;
	l2=1;
	r=n;
	r2=a[r].id;
	while((l<r&&addd%2==1)||((l<r||l2<r2)&&addd%2==0)){
		if(l>r&&l2>=r2){
			break;
		}
		if(a[l].id==a[r].id&&l2==1&&r2==a[r].id&&a[l].word!=a[r].word){
			add(a[l].id);
			l++;r--;
			l2=a[l].id+1;r2=0;		
			if(l>r&&l2>=r2){
				break;
			}
			l2=1;r2=a[r].id;
		}
		else{
			if(a[l].word!=a[r].word){
				add(1);
			}
			l2++;
			r2--;
			if(l2>a[l].id){
				l++;
				l2=1;
			}
			if(r2<1){
				r--;
				r2=a[r].id;
			}
		}
	}
	for(int i=lon;i>=1;i--){
		cout<<s[i];
	}
	return 0;
}
