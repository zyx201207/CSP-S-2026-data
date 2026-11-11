//GZ-J00246 华东师范大学附属贵阳学校 杨昊宸
#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
struct duan{
	ll num;
	char zf;
};
const int N=2e5+3;
ll s[N],num;
duan yc[N],yc2[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>yc2[i].num;
		cin>>yc2[i].zf;
		s[i]=s[i-1]+yc2[i].num;
	}
	num=s[n];
	ll mid=0;
	if(num%2==0){
		mid=num/2;
	}else{
		mid=num/2+1;
	}
	int wz=lower_bound(s+1,s+n+1,mid)-s;
	ll dbf=s[wz]-mid;//dbf记录中间的一组还剩下多少属于右半边
	//测试代码 
	//cout<<wz<<' '<<dbf<<'\n';
	for(int i=1;i<wz;++i){
		yc[i].num=yc2[i].num;
		yc[i].zf=yc2[i].zf;
	}
	yc[wz].num=yc2[wz].num-dbf;
	yc[wz].zf=yc2[wz].zf;
	int py=1;
	if(dbf>0){
		py=2;
		yc[wz+1].num=dbf;
		yc[wz+1].zf=yc2[wz].zf;
	}
	for(int i=wz+py;i<=n;++i){
		yc[i].num=yc2[i].num;
		yc[i].zf=yc2[i].zf;
	}
	//测试代码
	//cout<<"切分完成，剩余"<<dbf<<'\n'; 
	int a=1,b=n;
	ll ans=0;
	//测试代码
	//return 0; 
	while((b>wz)&&(a<=wz)){//a,b记录的是原数据下表 
		//测试代码
		//cout<<"处理中"<<'\n'; 
		if((yc[a].num==yc[b].num)&&(yc[a].zf==yc[b].zf)){
			yc[a].num=0;
			yc[b].num=0;
			a+=1;
			b-=1;
		}else if(yc[a].num!=yc[b].num){
			if(yc[a].zf==yc[b].zf){
				if(yc[a].num<yc[b].num){
					yc[b].num=yc[b].num-yc[a].num;
				}else{
					yc[a].num=yc[b].num-yc[a].num;
				}
				b-=1;
				//测试代码
				//cout<<"处理序号："<<b<<" 字符："<<yc[b].zf<<" z："<<yc[a].num<<'\n'; 
			}else{
				int z=0;//累加直到相等
				while(z<yc[a].num&&b>wz){
					//测试代码
					//cout<<"处理序号："<<b<<" 字符："<<yc[b].zf<<'\n'; 
					if(yc[b].zf!=yc[a].zf){
						z+=yc[b].num;
						ans+=yc[b].num;
						yc[b].num=0;
						if(z>yc[a].num){
							yc[b].num+=z-yc[a].num;
							z-=yc[b].num;
							b-=1;
							ans-=yc[b].num;
							break;
						}
						b-=1;
						//cout<<"======"<<a<<' '<<b<<'\n';
						//测试代码
						//cout<<"异字符分支"<<'\n';
					}else{
						if(!(yc[a].num-z<=yc[b].num)){
							yc[b].num=yc[b].num-(yc[a].num-z);
							b-=1;
							break;
						}else{
							z+=yc[b].num;
							yc[b].num=0;
							b-=1;
						}
						//测试代码
						//cout<<"TAT"<<'\n';
						//cout<<"同字符分支"<<'\n';
					}
					//cout<<"累加循环"<<'\n';
				}
			}
		}
		//测试代码
		//cout<<a<<' '<<b<<'\n'; 
		//cout<<"处理循环"<<'\n';
		//if(!(a==2&&b==4))return 0;
	}
	//测试代码
	//cout<<ans; 
	
	ll ans2=0;
	a=n,b=1;
	while((a>wz)&&(b<=wz)){//a,b记录的是原数据下表 
		//测试代码
		//cout<<"处理中"<<'\n'; 
		if((yc[a].num==yc[b].num)&&(yc[a].zf==yc[b].zf)){
			yc[a].num=0;
			yc[b].num=0;
			a-=1;
			b+=1;
		}else if(yc[a].num!=yc[b].num){
			if(yc[a].zf==yc[b].zf){
				if(yc[a].num<yc[b].num){
					yc[b].num=yc[b].num-yc[a].num;
				}else{
					yc[a].num=yc[b].num-yc[a].num;
				}
				b+=1;
				//测试代码
				//cout<<"处理序号："<<b<<" 字符："<<yc[b].zf<<" z："<<yc[a].num<<'\n'; 
			}else{
				int z=0;//累加直到相等
				while(z<yc[b].num&&a>wz){
					//测试代码
					//cout<<"处理序号："<<b<<" 字符："<<yc[b].zf<<'\n'; 
					if(yc[b].zf!=yc[a].zf){
						z+=yc[b].num;
						ans2+=yc[b].num;
						yc[b].num=0;
						if(z>yc[a].num){
							yc[b].num+=z-yc[a].num;
							z-=yc[b].num;
							b+=1;
							ans2-=yc[b].num;
							break;
						}
						b+=1;
						//cout<<"======"<<a<<' '<<b<<'\n';
						//测试代码
						//cout<<"异字符分支"<<'\n';
					}else{
						if(!(yc[a].num-z<=yc[b].num)){
							yc[b].num=yc[b].num-(yc[a].num-z);
							b+=1;
							break;
						}else{
							z+=yc[b].num;
							yc[b].num=0;
							b+=1;
						}
						//测试代码
						//cout<<"TAT"<<'\n';
						//cout<<"同字符分支"<<'\n';
					}
					//cout<<"累加循环"<<'\n';
				}
			}
		}
		//测试代码
		//cout<<a<<' '<<b<<'\n'; 
		//cout<<"处理循环"<<'\n';
		//if(!(a==2&&b==4))return 0;
	}
	//测试代码
	//cout<<ans2; 
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
