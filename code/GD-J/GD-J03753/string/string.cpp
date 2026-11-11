#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5+5;
struct chart{
	long long cnt;
	char c;
}a[N];
void solve(){
	int n;
	long long cnt = 0,sum = 0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
		//cout<<i<<" "<<a[i].cnt<<" "<<a[i].c<<endl;
		cnt+=a[i].cnt;
	}
	//cout<<endl;
	int i = 1,j = n;
	while(i<j){
		if(a[i].c!=a[j].c){
			//cout<<i<<"c!="<<j<<"c"<<" ";
			if(a[i].cnt>a[j].cnt){
				//cout<<a[j].cnt<<endl;
				a[i].cnt-=a[j].cnt;
				sum+=a[j].cnt;
				j--;
				//cout<<"sum+="<<a[j].cnt;
			}else if(a[i].cnt<a[j].cnt){
				a[j].cnt-=a[i].cnt;
				sum+=a[i].cnt;
				i++;
				//cout<<"sum+="<<a[i].cnt;
			}else{
				sum+=a[i].cnt;
				//cout<<"sum+="<<a[j].cnt;
				i++,j--;
			}
		}else{
			//cout<<i<<"c=="<<j<<"c"<<" ";
			if(a[i].cnt>a[j].cnt){
				a[i].cnt-=a[j].cnt;
				j--;
			}else if(a[i].cnt<a[j].cnt){
				a[j].cnt-=a[i].cnt;
				i++;
			}else{
				i++,j--;
			}
		}
		//cout<<endl;
	}
	cout<<sum<<endl;
	return;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
