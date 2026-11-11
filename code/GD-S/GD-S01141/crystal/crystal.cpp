#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=1,result=1;
string a[500001],m,cnt="0";
queue<string> q;
bool cmp(string x1,string x2){
	if(x1[0]=='-'&&x2[0]=='-')return x1.compare(x2)==1;
	else return x1.compare(x2)==-1;
}
string add(string x1,string x2){
	string res;int cnt=-1,more=0;
	reverse(x1.begin(),x1.end());
	for(int i=0;i<=max(x1.size(),x2.size())-1;i++){
		int num1,num2,sum;
		if(i>=x1.size())num1=0;
		else num1=x1[i]-'0'+0;
		if(i>=x2.size())num2=0;
		else num2=x2[i]-'0'+0;
		sum=num1+num2+more;more=0;
		if(sum>=10)sum-=10,more++;
		res=res+char('0'+sum);
	}
	if(more)res+='1';
	reverse(res.begin(),res.end());
	return res;
}
string mus(string x1,string x2){
	string res;int used=0;
	reverse(x1.begin(),x1.end());
	reverse(x2.begin(),x2.end());
	for(int i=0;i<=max(x1.size(),x2.size())-1;i++){
		int num1,num2,sum;
		if(i>=x1.size())num1=0;
		else num1=x1[i]-'0'+0;
		if(i>=x2.size())num2=0;
		else num2=x2[i]-'0'+0;
		sum=num1-num2-used;used=0;
		if(sum<0)sum+=10,used++;
		if(sum!=0||i!=max(x1.size(),x2.size())-1)res=res+char('0'+sum);
	}
	reverse(res.begin(),res.end());
	return res;
}
string turn(int x){
	string res;int cnt=-1;
	while(x!=0)res+=char(x%10+'0'),x/=10;
	return res;
}
int offturn(string x){
	int res=0;
	for(int i=x.size()-1;i>=0;i--)res+=(x[i]-'0'+0)*pow(10,x.size()-1-i);
	return res;
}
void ret(){
	for(int i=1;i+cnt.size()<=18;i++)cnt="0"+cnt;
	for(int i=1;i+m.size()<=18;i++)m="0"+m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i][0]!='-'){
			for(int j=1;j+a[i].size()<=12;j++){
				a[i]="0"+a[i];
			}
		}
		
	}
	sort(a+1,a+1+n,cmp);
//	cout<<"a[i] : ";
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n;i++){
		ret();
		if(q.empty()){q.push(a[i]);continue;}
		string cu=q.back();q.push(a[i]);
//		cout<<"The "<<i<<" round "<<endl;
//		cout<<"The number is "<<a[i]<<endl;
		cnt=add(cnt,turn(offturn(mus(q.back(),cu))*(q.size()-1)));
//		cout<<"Cost : "<<cnt<<endl;
		if(cnt.compare(m)<1)ans++;
		else while(cnt.compare(m)==1)ret(),cnt=mus(cnt,mus(q.back(),q.front())),q.pop(),ans--;
//		cout<<cnt<<endl;
		result=max(result,ans);
//		cout<<"ans : "<<ans<<"  Result now : "<<result<<endl;
	}
	cout<<result<<endl;
	return 0;
}
