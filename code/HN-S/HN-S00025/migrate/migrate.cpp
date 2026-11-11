#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

void setio(string filename,string inSu=".in",string outSu=".out"){
	string in=filename+inSu;
	string out=filename+outSu;
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
}

template<typename t>
class link{
public:
	class iterator;
private:
	struct node{
		t data;
		node *next,*prev;
		node(t data):data(data),next(nullptr),prev(nullptr){}
	}*head,*tail;
	size_t si;
public:
	class iterator{
	public:
		iterator(link<t>::node *p){
			this->p=p;
		}
		iterator():p(nullptr){}
		t operator*(void){
			if(p)
				return this->p->data;
		}
		iterator operator++(int){
			iterator tmp=*this;
			if(p)
				this->p=this->p->next;
			return tmp;
		}
		iterator& operator++(void){
			if(p)
				this->p=this->p->next;
			return *this;
		}
		iterator operator--(int){
			iterator tmp=*this;
			if(p)
				this->p=this->p->prev;
			return tmp;
		}
		iterator& operator--(void){
			if(p)
				this->p=this->p->prev;
			return *this;
		}
		bool to_bool(void) const {
			if(p)
				return true;
			else
				return false;
		}
		bool operator!(void) const {
			if(p)
				return false;
			else
				return true;
		}
		bool operator==(link<t>::iterator other){
			return this->p==other.p;
		}
		bool operator!=(link<t>::iterator other){
			return !(this->p==other.p);
		}
		iterator& operator+(size_t add){
			for(size_t i=0;i<add;i++)
				this->operator++(1);
		}
		iterator& operator-(size_t sub){
			for(size_t i=0;i<sub;i++)
				this->operator--(1);
		}
	private:
		link<t>::node *p;
		friend class link;
	};
private:
	t defultfill(size_t idx){
		return 0;
	}
	iterator getIteratorByIdx(size_t idx) const {
		node* curr;
		if(idx>this->si/2){
			curr=tail;
			for(size_t i=si;i>idx;i--)
				curr=curr->prev;
			return iterator(curr);
		}
		else if(idx<=this->si/2){
			curr=head;
			for(size_t i=0;i<idx;i--)
				curr=curr->next;
			return iterator(curr);
		}
	}
public:
	size_t size(void) const {
		return si;
	}
	bool empty(void) const {
		return si==0;
	}
	link(){
		head=tail=nullptr;
		si=0;
	}
	link(size_t gsi,t fillvalue){
		si=0;
		for(size_t i=0;i<gsi;i++)
			push_back(fillvalue);
	}
	link(size_t gsi,t (*fillidx)(size_t idx)=defultfill){
		si=0;
		for(size_t i=0;i<gsi;i++)
			push_back(fillidx(i));
	}
	~link(void){
		clear();
	}
	void clear(void){
		if(empty())
			return;
		node *curr=head;
		for(size_t i=0;i<si;i++){
			node *del=curr;
			if(curr->next)curr=curr->next;
			delete del;
		}
		si=0;
	}
	void push_back(t x){
		node* newnode=new node(x);
		if(empty()){
			head=tail=newnode;
		}
		else{
			tail->next=newnode;
			newnode->prev=tail;
			tail=tail->next;
		}
		si++;
	}
	void push_front(t x){
		node* newnode=new node(x);
		if(empty()){
			head=tail=newnode;
		}
		else{
			head->prev=newnode;
			newnode->next=head;
			head=head->prev;
		}
		si++;
	}
	void pop_back(void){
		node* del=tail;
		if(!empty()){
			if(si!=1){
				tail->prev->next=nullptr;
				tail=tail->prev;
			}
			delete del;
			si--;
		}
	}
	void pop_front(void){
		node* del=head;
		if(!empty()){
			if(si!=1){
				head->next->prev=nullptr;
				head=head->next;
			}
			delete del;
			si--;
		}
	}
	
	void push_back(link<t>::iterator x){
		node* newnode=x.p;
		if(empty()){
			head=tail=newnode;
		}
		else{
			tail->next=newnode;
			newnode->prev=tail;
			tail=tail->next;
		}
		si++;
	}
	void push_front(link<t>::iterator x){
		node* newnode=x.p;
		if(empty()){
			head=tail=newnode;
		}
		else{
			head->prev=newnode;
			newnode->next=head;
			head=head->prev;
		}
		si++;
	}
	link(const link<int>& other){
		if(&other==this)
			return;
		else{
			clear();
			for(auto it=other.begin();it!=other.end();it++){
				push_back(*it);
			}
		}
	}
	iterator begin(void) const {
		return head;
	}
	iterator end(void) const {
		return iterator();
	}
	t front(void) const {
		return this->head->data;
	}
	t back(void) const {
		return this->tail->data;
	}
	link<t>& operator+(link<t> other){
		for(auto it=other.begin();it!=other.end();it++){
			push_back(*it);
		}
	}
	void insert(link<t>::iterator it,t value){
		node *newnode=new node(value);
		if(empty()){
			if(!it){
				head=tail=newnode;
			}
		}
		else if(it.to_bool()){
			node *curr=it.p;
			if(curr==tail)
				push_back(value);
			else if(curr==head)
				push_front(value);
			else{
				node* newnode=new node(value);
				newnode->prev=curr;
				newnode->next=curr->next;
				curr->next->prev=newnode;
				curr->next=newnode;
			}
		}
		si++;
	}
	void insert(size_t idx,t value){
		insert(getIteratorByIdx(idx),value);
	}
	void erase(link<t>::iterator it){
		if(it.to_bool()){
			node *del=it.p;
			if(del==tail)
				pop_back();
			else if(del==head)
				pop_front();
			else{
				node *delprev=del->prev;
				delprev->next=del->next;
				del->next->prev=delprev;
				delete del;
			}
		}
		si--;
	}
	void erase(link<t>::iterator itF,link<t>::iterator itE){
		if(itF.to_bool() && itE.to_bool()){
			if(itF.p==head)
				if(itE.p=tail){
					clear();
					return;
				}
				else{
					while(head!=itE.p->next)
						pop_front();
					return;
				}
			if(itE.p==tail)
				if(itF.p==head){
					clear();
					return;
				}
				else{
					while(tail!=itF.p->prev)
						pop_back();
					return;
				}
			node *delsprev=itF.p->prev;
			node *delsnext=itE.p->next;
			node *curr=itF.p;
			while(curr!=delsnext){
				node *del=curr;
				curr=curr->next;
				delete del;
				si--;
			}
			delsprev->next=delsnext;
			delsnext->prev=delsprev;
		}
	}
	void erase(link<t>::iterator it,size_t length){
		link<t>::iterator itE=it+length;
		erase(it,itE);
	}
	void erase(size_t idx){
		erase(getIteratorByIdx(idx));
	}
	void erasr(size_t start,size_t length){
		erase(getIteratorByIdx(start),length);
	}
	link<t> operator=(link<t> other){
		if(&other==this)
			return;
		else{
			clear();
			for(auto it=other.begin();it!=other.end();it++){
				push_back(*it);
			}
		}
	}
};

int fillidx(size_t idx){
	return static_cast<int>(idx);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	setio("migrate");
	return 0;
}

