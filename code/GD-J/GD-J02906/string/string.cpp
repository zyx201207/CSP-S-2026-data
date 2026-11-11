#include<iostream>//string
#include<deque>
using namespace std;
string s;
deque<char> d;
char c[2000002];
long long a[2000006],n,m=1,an;
int main(){
	freopen("string.in","r",stdin);//别住释！！！！
	freopen("string.out","w",stdout);//别住释！！！！ 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		c[0]=c[1];
		if(c[i-1]==c[i])m++;
		else m=-10033;
	}
	if(m>0){
		cout<<0;
		return 0;
	}
	m=1;
	for(int i=2;i<=n;i++){
		if(a[i]=a[i-1])m++; 
		else m=-1111;
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			d.push_back(c[i]);
		}
	}
	int ddd=d.size();
	for(int i=0;i<=ddd;i++){
		if(d.size()==1){
			break;
		}
			if((!d.empty()&&d.front()!=d.back())){
				an++;
				d.pop_back();
				d.pop_front();
			}	
	}
			cout<<an;

	
	
	
	
	return 0;
} 
