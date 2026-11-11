#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,x,y;
inline int read(){
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		ch=getchar();
	}
	int s=0;
	while(ch>='0' && ch<='9'){
		s=s*10+ch-48;
		ch=getchar();
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(m==n){
		ans=a[1];
		for(int i1=2;i1<=n;i1++){
			ans=ans&a[i1];
		}
	}
	else if(m==n-1){
		for(int i1=1;i1<=n;i1++){
			if(i1==1){
				int s=a[2];
				for(int j=3;j<=n;j++){
					s=s&a[j];
				}
				ans=max(ans,s);
			}
			else {
				int s=a[1];
				for(int j=2;j<=n;j++){
					if(j==i1) continue;
					s=s&a[j];
				}
				ans=max(ans,s);
			}
			
		}
	}
	else if(m==1){
		for(int i1=1;i1<=n;i1++){
			ans=max(ans,a[i1]);
		}
	}
	else if(m==2){
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)ans=max(ans,a[i1]&a[i2]);
	}
	else if(m==3){
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)ans=max(ans,a[i1]&a[i2]&a[i3]);
	}
	else if(m==4){
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]);
	}
	else if(m==5){
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]);
	}
	else if(m==6){
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]);
							
	}
	else if(m==7){
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]);
	}
	else if(m==8){
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]);
	}
	else if(m==9){
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]);
	}else if(m==10){
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]);
	}
	else if(m==11){
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												for(int i11=i10+1;i11<=n;i11++)ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]);
	}
	else if(m==11){
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												for(int i11=i10+1;i11<=n;i11++)
													for(int i12=i11+1;i12<=n;i12++)ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]);
	}
	cout<<ans;
}
