#include<bits/stdc++.h>
using namespace std;
string m,a[500005],c[500005],next,now;
int to[500005]={0};
int n;
string minu(string a,string b){
	int i,j;
	int a1[30],b1[30];
	j=0;
	for(i=a.length()-1;i>=0;i--){
		a1[j]=a[i]-48;j++;
	}
	j=0;
	for(i=b.length()-1;i>=0;i--){
		b1[j]=b[i]-48;j++;
	}
	for(i=0;i<b.length();i++){
		if(a1[i]<b1[i]){
			a1[i+1]-=1;
			a1[i]=a1[i]+10;
		}
		a1[i]-=b1[i];
	}
	for(i=0;i<a.length();i++){
		a[i]=a1[a.length()-i-1]+48;
	}
	return a;
}
string add(string a,string b){
	int i,j;
	int a1[30],b1[30];
	j=0;
	for(i=a.length()-1;i>=0;i--){
		a1[j]=a[i]-48;j++;
	}
	j=0;
	for(i=b.length()-1;i>=0;i--){
		b1[j]=b[i]-48;j++;
	}
	for(i=0;i<b.length();i++){
		if(a1[i]+b1[i]>=10){
			a1[i+1]+=1;
			a1[i]=a1[i]-10;
		}
		a1[i]+=b1[i];
	}
	for(i=0;i<a.length();i++){
		a[i]=a1[a.length()-i-1]+48;
	}
	return a;
}
bool cmp(string a,string b){
	int i;
	int a1[30]={0},b1[30]={0};
	for(i=0;i<a.length();i++){
		a1[i]=a[i]-48;
	}
	for(i=0;i<b.length();i++){
		b1[i]-b[i]-48;
	}
	for(i=20;i>=0;i--){
		if(a1[i]>b1[i]){
			return true;
		}else{
			return false;
		}
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n;
	int i,j;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=1;i<n;i++){
		c[i]=minu(a[i],a[i-1]);
	}
	next='0000000000000000000';	
	now='0000000000000000000';
	for(i=n-1;i>=0;i--){
		for(j=i;j>0;j--){
			next=add(next,c[j]);
			now=add(now,next);
			if(cmp(m,now)){
				break;
			}else{
				to[i]++;
			}
		}
		next='0000';now='0000000000000000';
	}
	sort(to,to+n);
	for(i=0;i<n;i++){
		cout<<to[i];
	}
	cout<<next;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
