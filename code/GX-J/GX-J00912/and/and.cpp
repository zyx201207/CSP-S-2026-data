#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],num[200010];

string totwo(ll t1){
	string st,s;
	while(t1>0){
		st+=tochar(t1%2);
		t1/=2;
	}
	for(ll i=st.size()-1;i>=0;i--){
		s+=st[i];
	}
	return s;
}

char tochar(ll t1){
	
	if(t1==0)return '0';
	if(t1==1)return '1';
	if(t1==2)return '2';
	if(t1==3)return '3';
	if(t1==4)return '4';
	if(t1==5)return '5';
	if(t1==6)return '6';
	if(t1==7)return '7';
	if(t1==8)return '8';
	if(t1==9)return '9';
	return '';
}

ll ctoll(char t1){
	if(t1=='0')return 0;
	if(t1=='1')return 1;
	if(t1=='2')return 2;
	if(t1=='3')return 3;
	if(t1=='4')return 4;
	if(t1=='5')return 5;
	if(t1=='6')return 6;
	if(t1=='7')return 7;
	if(t1=='8')return 8;
	if(t1=='9')return 9;
	return 0;
}

ll cf(ll t1,ll t2){
	ll t3=t1;
	for(ll i=2;i<=t2;i++){
		t3*=t1;
	}
	if(t2==0)return 1;
	else return t3;
}

string toten(string t1){
	string s;
	ll j=0,t2=0;
	for(ll i=t1.size()-1;i>=0;i--){
		t2+=cf(ctoll(t1[i]),j);
		j++;
	}
	return tos(t2);
}

ll stoll(string t1){
	ll t2=0;
	for(ll i=0;i<t1.size();i++){
		t2=t2*10+ctoll(t1[i]);
	}
	return t2;
}

string tos(ll t1){
	string st,s;
	while(t1>0){
		st+=tochar(t1%10);
		t1/10;
	}
	for(ll i=s.size()-1;i>=0;i--){
		s+=st[i];
	}
	return s;
}

ll and1(string t1,string t2){
	string t3,t4;
	for(ll i=min(t1.size(),t2.size())-1;i>=0;i--){
		if(t1[i]==t2[i])t3+='1';
		else t3+='0';
	}
	for(ll i=t3.size()-1;i>=0;i--){
		t4+=t3[i];
    }
    ll t5=stoll(t4);
    return t5;
}

ll finda(){
	ll t1max=-1;
	for(ll i=0;i<=n-m;i++){
		ll t1=a[i];
		for(ll j=i;j<=i+m;j++){
			t1=and1(tos(t1),tos(a[j]));
		}
		t1max=max(t1,t1max);
	}
	return t1max;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<finda()<<endl;
	
	return 0;
}
